using Npgsql;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using Tasker.Model;
using Tasker.View;
using Task = Tasker.Model.Task;

namespace Tasker.ViewModel
{
    public class MainWindowVM
    {
        /*
         * Commands
         */
        public ICommand Add { get; set; }
        public ICommand Update { get; set; }
        public ICommand Remove { get; set; }
        public ICommand Clear { get; set; }

        /*
         *  UI mapping
         */
        public Task SelectedTask { get; set; }

        public IDatabase connection = new Postgres();
        public ObservableCollection<ITable> Tasks { get; set; }
        public MainWindowVM()
        {
            CreateCommands();
            LoadTasks();
        }

        private void LoadTasks()
        {
            List<ITable> tasks = connection.Select("*", typeof(Task), "");
            Tasks = new ObservableCollection<ITable>(tasks);
        }

        public void CreateCommands()
        {
            Add = new RelayCommand((object _) =>
            {
                Task task = new Task();
                task.DueUntil = DateTime.Now; // prevent showing 01/01/01 in the date picker

                AddTaskView window = new AddTaskView();
                window.DataContext = task;
                bool? isAccepted = window.ShowDialog();

                if (isAccepted.HasValue && isAccepted.Value)
                {
                    Task newTask = (Task) connection.Table("task").Insert(task);
                    Tasks.Add(newTask);
                }
            });

            Remove = new RelayCommand((object _) =>
            {
                string query = String.Format("DELETE FROM task WHERE id = {0}", SelectedTask.Id);
                connection.Table("task").Delete(query);
                Tasks.Remove(SelectedTask);
            });

            Update = new RelayCommand((object _) =>
            {
                Task updatedTask = SelectedTask.Clone();

                UpdatedTaskView window = new UpdatedTaskView();
                window.DataContext = updatedTask;
                bool? isAccepted = window.ShowDialog();

                if (isAccepted.HasValue && isAccepted.Value)
                {
                    connection.Table("task").Update(updatedTask);
                    SelectedTask.Title = updatedTask.Title;
                    SelectedTask.DueUntil = updatedTask.DueUntil;
                    SelectedTask.Status = updatedTask.Status;
                }
            });

            Clear = new RelayCommand((object _) =>
            {
                string query = String.Format("DELETE FROM task");
                connection.Table("task").Delete(query);
                Tasks.Clear();
            });
        }
    }
}
