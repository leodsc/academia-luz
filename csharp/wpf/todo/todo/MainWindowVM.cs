using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace todo
{
    public class MainWindowVM
    {

        public ICommand Add { get; set; }
        public ICommand Remove { get; set; }
        public ICommand Update { get; set; }
        public ICommand Clear { get; set; }

        public Todo SelectedTodo { get; set; }
        public string Title { get; set; }
        public DateTime DueUntil { get; set; }
        public string Today { get; set; }
        public ObservableCollection<Todo> Todos { get; set; }

        public MainWindowVM() 
        { 
            Todos = new ObservableCollection<Todo>();
            DueUntil = DateTime.Now;
            CreateCommands();
        }

        //private void CreateCommands()
        {
            Add = new RelayCommand((object _) => {
                CreateTodo createTodoWindow = new CreateTodo();
                Todo todo = new Todo();
                todo.DueUntil = DateTime.Now;
                createTodoWindow.DataContext = todo;

                bool? isAccepted = createTodoWindow.ShowDialog();
                if (isAccepted.HasValue && isAccepted.Value)
                {
                    Todos.Add(todo);
                }
            });

            Remove = new RelayCommand((object _) =>
            {
                Todos.Remove(SelectedTodo);
            });

            Clear = new RelayCommand((object _) =>
            {
                Todos.Clear();
            });

            Update = new RelayCommand((object _) =>
            {
                Todo newTodo = SelectedTodo.Clone();

                UpdateTodo window = new UpdateTodo();
                window.DataContext = newTodo;
                bool? isAccepted = window.ShowDialog();

                if (isAccepted.HasValue && isAccepted.Value)
                {
                    SelectedTodo.Title = newTodo.Title;
                    SelectedTodo.DueUntil = newTodo.DueUntil;
                }
            });
        }
    }
}
