using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace guessr
{
    public class Game
    {
        private int CurrentBlock = 0;
        public ObservableCollection<string> Word { get; set; }
        public Game() 
        {
            Word = new ObservableCollection<string>(new string[5]);
        }

        public void AddLetter(Key key, int position)
        {
            if (Convert.ToInt16(key) >= 44 && Convert.ToInt16(key) <= 69)
            {
                Word[position] = key.ToString();
            }
        }

        public void CallKey(KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                Console.WriteLine(String.Join("", Word));
            } 
            else if (e.Key == Key.Back) 
            {
                eraseCharacter();
            } 
            else 
            {
                AddLetter(e.Key, CurrentBlock);
                if (CurrentBlock < 4)
                    CurrentBlock++;
            }
        }

        private void eraseCharacter()
        {
            if (CurrentBlock > 0)
            {
                Word[CurrentBlock] = ""; 
                CurrentBlock--;
            }
        }
    }
}
