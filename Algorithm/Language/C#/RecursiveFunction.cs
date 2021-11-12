using System;

namespace RecursiveFunction
{
    class MainClass
    {
        /*
            フィボナッチ数列(Fibonacci number)
            f(n) = f(n-1) + f(n-2)
            1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181・・・
            の第n項目を求める
        */
        public static void Main(string[] args)
        {
            Console.WriteLine(Fibonacci(5)); // 5
            Console.WriteLine(Fibonacci(6)); // 8
        }
        private static long Fibonacci(int n)
        {
            // 初項を1として数えた場合に一致するように記載
            // 以下のif文がないと無限ループする
            if (n == 1 || n == 2)
            {
                return 1;
            }
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
    }
}
