using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace todo
{
    /// <summary>
    /// Lógica interna para UpdateTodo.xaml
    /// </summary>
    public partial class UpdateTodo : Window
    {

        public UpdateTodo()
        {
            InitializeComponent();
        }

        private void btnClick_Update(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
        }

        private void btnClick_Close(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}
