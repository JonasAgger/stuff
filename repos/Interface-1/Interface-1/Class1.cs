using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


public class DoHickey : IDoThings
{

    public void DoNothing()
    {
        System.Console.WriteLine("DoHickey::DoNothing");
    }

    public int DoSomething(int number)
    {
        System.Console.WriteLine("DoHickey::DoSomething(): {}", number);
        return number;
    }

    public string DoSomethingElse(string input)
    {
        System.Console.WriteLine("DoHickey::DoSomethingElse(): {}", input);
        return input;
    }
}


public interface IDoThings
{
    void DoNothing();
    int DoSomething(int number);
    string DoSomethingElse(string input);
}

