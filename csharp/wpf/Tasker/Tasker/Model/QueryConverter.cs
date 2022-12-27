using Npgsql;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls.Primitives;

namespace Tasker.Model
{
    public class QueryConverter 
    {
        private NpgsqlDataReader Rows;
        public static QueryConverter Instance { get; } = new QueryConverter();

        private QueryConverter() { }

        private List<string> generateColumnsNames()
        {
            List<string> columns = new List<string>();
            int TOTAL_COLUMNS = Rows.FieldCount;

            for (int i = 0; i < TOTAL_COLUMNS; i++)
            {
                columns.Add(Rows.GetName(i));
            }

            return columns;
        }

        public QueryConverter From(NpgsqlDataReader rows)
        {
            Rows = rows;
            return Instance;
        }

        public List<ITable> To(Type table)
        {
            List<ITable> list = new List<ITable>();
            List<string> columns = generateColumnsNames();
            Dictionary<string, object> placeholder = new Dictionary<string, object>();

            if (table == typeof(Task))
            {
                int counter = 0;
                while (Rows.Read())
                {

                    placeholder.Add(Rows.GetName(counter), Rows[counter]);

                    if (counter == Rows.FieldCount-1)
                    {
                        Task task = (Task) Activator.CreateInstance(table, placeholder);
                        placeholder = new Dictionary<string, object>();
                        list.Add(task);
                        counter = 0;
                    } else
                    {
                        counter++;
                    }
                }
            }

            return list;
        }
    }
}
