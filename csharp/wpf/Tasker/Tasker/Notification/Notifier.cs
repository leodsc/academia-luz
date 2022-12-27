using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Tasker.Notification
{
    public class Notifier : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        public void NotifyPropertyChange(object classTarget, string property) 
        {
            PropertyChanged?.Invoke(classTarget, new PropertyChangedEventArgs(property));
        }
    }
}
