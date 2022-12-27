using Npgsql;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tasker.Model
{
    public interface IDatabase
    {
        List<Dictionary<string, object>> Select(string columns, string query);
        ITable Insert(ITable obj);
        void Delete(string query);
        void Update(ITable obj);

        IDatabase Table(string tableName);
    }
}
