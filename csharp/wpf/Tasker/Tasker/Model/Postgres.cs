using Npgsql;
using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Tasker.Model
{
    public class Postgres : IDatabase
    {

        private readonly string serverName = "127.0.0.1";
        private readonly string port = "5432";
        private readonly string userName = "postgres";
        private readonly string password = "budsantos12";//Environment.GetEnvironmentVariable("PSQL_ROOT_PASSWORD");
        private readonly string databaseName = "Tasker";
        private string tableName;
        private NpgsqlConnection pgsqlConnection;

        public Postgres() { }

        private void CloseConnection()
        {
            pgsqlConnection.Close();
        }

        private void CreateConnection()
        {
            string connection = String.Format("Server={0};Port={1};User Id={2};Password={3};Database={4};",
                                                serverName, port, userName, password, databaseName);
            try
            {
                pgsqlConnection = new NpgsqlConnection(connection);
                pgsqlConnection.Open();
                Console.Write("Database was connected!");
            } catch (Exception exc)
            {
                throw exc;
            }
        }

        public IDatabase Table(string tableName)
        {
            this.tableName = tableName;
            return this;
        }

        public List<ITable> Select(string query, Type table)
        {
            List<ITable> list = new List<ITable>();

            NpgsqlCommand cmd = new NpgsqlCommand(query, pgsqlConnection);
            NpgsqlDataReader dr = cmd.ExecuteReader();

            return list;
        }

        public List<ITable> Select(string columns, Type table, string extras)
        {
            CreateConnection();
            List<ITable> list = new List<ITable>();
            Dictionary<string, object> dict = new Dictionary<string, object>();

            string query = String.Format("SELECT {0} FROM task {1} ", columns, extras);

            NpgsqlCommand cmd = new NpgsqlCommand(query, pgsqlConnection);
            NpgsqlDataReader dr = cmd.ExecuteReader();

            while (dr.Read())
            {
                for (int i = 0; i < dr.FieldCount; i++)
                {
                    dict.Add(dr.GetName(i), dr[i]);
                }

                ITable collection = (ITable) Activator.CreateInstance(table, dict);

                dict = new Dictionary<string, object>();
                list.Add(collection);
            }

            CloseConnection();
            return list;
        }

        public ITable Insert(ITable obj)
        {
            CreateConnection();
            string columns = "";
            string values = "";

            int i = 0;
            foreach (var prop in obj.GetType().GetProperties())
            {
                if (prop.GetValue(obj) != null && prop.Name.ToLower() != "id")
                {
                    columns += String.Format("{0}", prop.Name);
                    values += String.Format("'{0}'", prop.GetValue(obj));
            
                    bool isLastColumn = i == obj.GetType().GetProperties().Length - 1;
                    if (!isLastColumn)
                    {
                        columns += ", ";
                        values += ", ";
                    }
                }

                i++;
            }

            string query = String.Format("INSERT INTO {0} ({1}) VALUES({2}) RETURNING id", tableName, columns.ToLower(), values);
            NpgsqlCommand cmd = new NpgsqlCommand(query, pgsqlConnection);
            object id = cmd.ExecuteScalar();
            obj.Id = Int32.Parse(id.ToString());

            CloseConnection();
            return obj;
        }

        public void Delete(string query)
        {
            CreateConnection();

            NpgsqlCommand cmd = new NpgsqlCommand(query, pgsqlConnection);
            cmd.ExecuteNonQuery();

            CloseConnection();
        }

        public void Update(ITable obj)
        {
            CreateConnection();
            if (obj.GetType() == typeof(Task))
            {
                Task task = (Task) obj;
                string updatedValues = "";

                int i = 0;
                foreach (var prop in task.GetType().GetProperties())
                {
                    if (prop.Name.ToLower() != "id")
                    {
                        updatedValues += String.Format("{0} = '{1}'", prop.Name.ToLower(), prop.GetValue(task));

                        bool isLastColumn = i == obj.GetType().GetProperties().Length - 1;
                        if (!isLastColumn)
                        {
                            updatedValues += ", ";
                        }
                    }
                    i++;
                }
                string query = String.Format("UPDATE {0} SET {1} WHERE id = {2}", tableName, updatedValues, task.Id);
                Console.WriteLine(query);
                NpgsqlCommand cmd = new NpgsqlCommand(query, NpgsqlConnection);
                cmd.ExecuteNonQuery();
            }


            CloseConnection();
        }

        public NpgsqlConnection NpgsqlConnection
        {
            get { return pgsqlConnection; }
        }
    }
}
