using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CardGame;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            
            Game game = new Game(3, 50);

            game.DealCards(5);

            game.ShowHands();

            game.AnnounceWinner();


        }
    }
}
