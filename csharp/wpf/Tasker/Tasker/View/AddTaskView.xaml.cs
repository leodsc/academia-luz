using System;
using System.Collections.Generic;
using System.Linq;
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

namespace Tasker.View
{
    /// <summary>
    /// Lógica interna para AddTaskView.xaml
    /// </summary>
    public partial class AddTaskView : Window
    {
        public AddTaskView()
        {
            InitializeComponent();
        }

        public void btnClick_Create(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
        }
    }
}
