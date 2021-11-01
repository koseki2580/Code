using System;
using System.Collections.Generic;
namespace Queue
{
    class MainClass
    {
        public static void Main()
        {
            Queue<int> s = new Queue<int>();
            s.Enqueue(1);
            s.Enqueue(2);
            s.Enqueue(3);
            Console.WriteLine(s.Peek()); // 1  s:[1,2,3]
            s.Enqueue(4);
            s.Dequeue();
            Console.WriteLine(s.Peek()); // 2  s:[2,3,4]
            s.Dequeue();
            Console.WriteLine(s.Peek()); // 3  s:[3,4]
            return;
        }
    }
}
