using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace CSharp_Learning
{
    class Test
    {
        [DllImport("DLL-CPP.dll", CallingConvention = CallingConvention.Cdecl)]
        extern static int Add(int a, int b);

        public static void test()
        {
            try
            {
                int a = 42;
                int b = 119;
                int c = Add(a, b);

                Console.WriteLine(c);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"ex:{ex}");
            }

            //Console.ReadLine();
        }
    }
}
