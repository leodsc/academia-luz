using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace todo
{
    public class Todo : INotifyPropertyChanged 
    {
        private string title;
        private bool status;

        private DateTime createdAt;
        private DateTime dueUntil;

        public event PropertyChangedEventHandler PropertyChanged;

        public Todo() { }

        public Todo(string title, bool status, DateTime dueUntil)
        {
            title = title;
            status = status;
            createdAt = DateTime.Now;
            dueUntil = dueUntil;
        }

        public Todo Clone()
        {
            return (Todo)this.MemberwiseClone();
        }

        private void RaisePropertyChanged(string prop)
        {
            this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }

        public string Title
        {
            get { return title; }
            set
            {
                title = value;
                RaisePropertyChanged("Title");
            }
        }
        public DateTime DueUntil 
        {
            get { return dueUntil; }
            set
            {
                dueUntil = value;
                RaisePropertyChanged("DueUntil");
            }
        }
    }
}
