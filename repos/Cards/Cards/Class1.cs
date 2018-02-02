using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.ComTypes;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

public enum Color
{
    Red = 1,
    Blue = 2,
    Green = 3,
    Yellow = 4
}

namespace CardGame
{
    public class Game
    {
        private List<Player> players = new List<Player>();
        private Deck deck;
        public Game(int numPlayers, int deckSize)
        {
            for (int i = 0; i < numPlayers; i++)
            {
                Console.Write("Enter player{0}'s name: ", i);
                string name = Console.ReadLine();
                players.Add(new Player(name));
            }

            deck = new Deck(deckSize);
        }

        public void DealCards(int howMany)
        {
            foreach(var player in players)
                deck.DealCards(howMany, player);
        }

        public void ShowHands()
        {
            foreach(var player in players)
                player.ShowHand();
        }

        public void AnnounceWinner()
        {
            int maxValue = 0;
            String name = "wat";

            foreach (var player in players)
            {
                if (player.ValueOfHand() > maxValue)
                {
                    maxValue = player.ValueOfHand();
                    name = player._name;
                }
            }

            Console.WriteLine("THE WINNER IS: {0} WITH A HAND WORTH {1}", name, maxValue);

        }
    }

    public class Card
    {
        public int number { get; set; }
        public Color cardColor { get; set; }

        public Card(int number_, Color cardColor_)
        {
            number = number_;
            cardColor = cardColor_;
        }

        public string GetSuit()
        {
            switch (cardColor)
            {
                case Color.Blue:
                    return "Blue";
                case Color.Green:
                    return "Green";
                case Color.Red:
                    return "Red";
                case Color.Yellow:
                    return "Yellow";
            }

            return "wat";
        }

        public int GetValue()
        {
            return number * (int)cardColor;
        }



    }

    public class Player
    {
        private List<Card> Cards = new List<Card>();
        public String _name { get; set; }

        public Player(string name)
        {
            _name = name;
        }

        public void GetCard(Card card)
        {
            Cards.Add(card);
        }

        public int ValueOfHand()
        {
            int total = 0;
            foreach (var card in Cards)
            {
                total += card.GetValue();
            }

            return total;
        }

        public void ShowHand()
        {
            Console.WriteLine("{0} has the following cards in hand:", _name);
            foreach (var card in Cards)
            {
                Console.WriteLine("{0} {1}", card.GetSuit(), card.number);
            }
        }
    }

    public class Deck
    {
        private List<Card> deck = new List<Card>();

        public Deck(int deckSize)
        {
            Random rdn = new Random(DateTime.Now.Millisecond);

            for (int i = 0; i < deckSize; i++)
            {
                deck.Add(new Card(rdn.Next(1,9), (Color)rdn.Next(1,5)));
            }
        }

        public void DealCards(int numberOfCards, Player player)
        {
            for (int i = 0; i < numberOfCards; i++)
            {
                player.GetCard(deck.First());
                deck.Remove(deck.First());
            }
        }
    }
}
