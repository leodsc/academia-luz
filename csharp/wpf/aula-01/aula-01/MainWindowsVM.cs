using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace aula_01
{
    public class MainWindowsVM : INotifyPropertyChanged
    {

        public string nome { get; set; }
        public ObservableCollection<string> lista { get; set; }
        public ICommand comando { get; private set; }
        public MainWindowsVM() 
        { 
            lista = new ObservableCollection<string>();
            nome = "Digite um nome";
            comando = new RelayCommand((object param) => {
                lista.Add(nome);
            });
        }

        public event PropertyChangedEventHandler PropertyChanged;

        public void Notifica(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
