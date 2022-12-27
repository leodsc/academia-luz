using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tasker.Model
{
    public interface ITable
    {
        int Id { get; set; }
        string ToString();
    }
}
