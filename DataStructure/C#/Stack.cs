using System;
using System.Collections.Generic;
namespace Stack
{
    class MainClass
    {
        public static void Main()
        {
            // 初期化
            Stack<int> s = new Stack<int>();

            // Push 要素を一番後ろに追加
            s.Push(1);
            s.Push(2);
            s.Push(3);
            Console.WriteLine(s.Peek()); // 3  s:[1,2,3]
            s.Push(4);
            Console.WriteLine(s.Peek()); // 4  s:[1,2,3,4]

            // Pop　一番後ろ（一番新しい）要素を取り除く
            s.Pop();
            s.Pop();
            Console.WriteLine(s.Peek()); // 2  s:[1,2]

            return;
        }
    }
}
