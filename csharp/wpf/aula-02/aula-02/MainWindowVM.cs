using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Windows.Media.Animation;

namespace aula_02
{
    public class MainWindowVM : INotifyPropertyChanged
    {
        public ObservableCollection<User> users { get; set; }
        public ICommand Add { get; private set; }
        public ICommand Remove { get; private set; }
        public string name { get; set; }
        public string password { get; set; }
        public string email { get; set; }

        public User selectedUser { get; set; }

        public MainWindowVM()
        {
            users = new ObservableCollection<User>();
            CreateCommand();
        }

        public event PropertyChangedEventHandler PropertyChanged;

        public void CreateCommand()
        {
            Add = new RelayCommand((object _) => {
                users.Add(new User(name, email, password));
                string[] inputs = resetInputs();
                notify(inputs);
            });

            Remove = new RelayCommand((object _) =>
            {
                users.Remove(selectedUser);
            });
        }

        private string[] resetInputs()
        {
            name = "";
            email = "";
            password = "";
            return new [] { "name", "email", "password" };
        }

        private void notify(string[] propertyNames)
        {
            foreach (string name in propertyNames)
            {
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
            }
        }
    }
}
