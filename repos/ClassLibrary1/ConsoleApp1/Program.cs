using System;
using ClassLibrary1;
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            MotorBike bike  = new MotorBike(new DieselEngine(120));

            bike.RunAtHalfSpeed();
        }
    }
}
