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
        List<ITable> Select(string columns, Type table, string extras);
        ITable Insert(ITable obj);
        void Delete(string query);
        void Update(ITable obj);

        IDatabase Table(string tableName);
    }
}
