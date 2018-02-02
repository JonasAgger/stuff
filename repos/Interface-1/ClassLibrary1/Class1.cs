using System;

public class DoHickey : IDoThings
{

    public void DoNothing()
    {
        Console.WriteLine("DoHickey::DoNothing");
    }

    public int DoSomething(int number)
    {
        Console.WriteLine("DoHickey::DoSomething(): {0}", number);
        return number;
    }

    public string DoSomethingElse(string input)
    {
        Console.WriteLine("DoHickey::DoSomethingElse(): {0}", input);
        return input;
    }
}

public class DoDickey : IDoThings
{

    public void DoNothing()
    {
        Console.WriteLine("DoDickey::DoNothing");
    }

    public int DoSomething(int number)
    {
        Console.WriteLine("DoDickey::DoSomething(): {0}", number);
        return number;
    }

    public string DoSomethingElse(string input)
    {
        Console.WriteLine("DoDickey::DoSomethingElse(): {0}", input);
        return input;
    }
}


public interface IDoThings
{
    void DoNothing();
    int DoSomething(int number);
    string DoSomethingElse(string input);
}
