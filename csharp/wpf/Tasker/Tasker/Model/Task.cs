using Npgsql;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using Tasker.Notification;

namespace Tasker.Model
{
    public class Task : ITable, INotifyPropertyChanged
    {
        public int Id { get; set; }
        private string title;
        private bool status;
        private DateTime dueUntil;
        private DateTime createdAt = DateTime.Now;

        public event PropertyChangedEventHandler PropertyChanged;

        public Task() {
            createdAt = DateTime.Now;
            status = false;
        }

        public Task(string title, bool status, DateTime dueUntil, DateTime createdAt)
        {
            this.title = title;
            this.status = status;
            this.dueUntil = dueUntil;
            this.createdAt = createdAt;
        }

        public Task(Dictionary<string, object> dict)
        {
            this.Id = (int) dict["id"];
            this.title = (string) dict["title"];
            this.status = (bool) dict["status"];
            this.dueUntil = (DateTime) dict["dueuntil"];
            this.createdAt = (DateTime) dict["createdat"];
        }
        public void NotifyPropertyChange(object classTarget, string property) 
        {
            PropertyChanged?.Invoke(classTarget, new PropertyChangedEventArgs(property));
        }

        public Task Clone()
        {
            return (Task) this.MemberwiseClone();
        }

        public static ObservableCollection<Task> FromDatabase(List<Dictionary<string, object>> tasksDict)
        {
            ObservableCollection<Task> tasks = new ObservableCollection<Task>();
            foreach (Dictionary<string, object> dict in tasksDict)
            {
                tasks.Add(new Task(dict));
            }
            return tasks;
        }

        public string Title { get { return title; } set
            {
                title = value;

                if (title != "")
                {
                    NotifyPropertyChange(this, "Title");
                }
            }}

        public bool Status { get { return status; } set
            {
                status = value;

                if (title != "")
                {
                    NotifyPropertyChange(this, "Status");
                }
            }}
        public DateTime DueUntil { get { return dueUntil; } set
            {
                dueUntil = value;

                if (title != "")
                {
                    NotifyPropertyChange(this, "DueUntil");
                }
            }}
        public DateTime CreatedAt { get { return createdAt; } set
            {
                createdAt = value;

                if (title != "")
                {
                    NotifyPropertyChange(this, "CreatedAt");
                }
            }}
    }
}
