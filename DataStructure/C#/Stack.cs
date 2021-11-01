using System;
using System.Collections.Generic;
namespace Stack
{
    class MainClass
    {
        public static void Main()
        {
            Stack<int> s = new Stack<int>();

            s.Push(1);
            s.Push(2);
            s.Push(3);
            Console.WriteLine(s.Peek()); // 3  s:[1,2,3]
            s.Push(4);
            Console.WriteLine(s.Peek()); // 4  s:[1,2,3,4]
            s.Pop();
            s.Pop();
            Console.WriteLine(s.Peek()); // 2  s:[1,2]

            return;
        }
    }
}
