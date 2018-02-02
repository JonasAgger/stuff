using System;
namespace ConsoleApp1
{
    class DoStuff : DoHickey
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Press 1 for DoHickey, and 2 for DoDickey");

            int key = Console.Read();

            IDoThings myStuff;

            if (key - '0' == 1)
            {
                myStuff = new DoHickey();
            }
            else if (key - '0' == 2)
            {
                myStuff = new DoDickey();
            }
            else
            {
                myStuff = new DoHickey();
            }

            myStuff.DoNothing();

            myStuff.DoSomething(5);

            myStuff.DoSomethingElse("hello from Dickey");
        }
    }
}
