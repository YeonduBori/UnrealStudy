using System;
using System.Collections.Generic;

namespace Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {
            QuickSort quickSort = new QuickSort();
            int[] array = {9,8,7,6,5,4,3,2,1};
            //List<int> result = quickSort.Sort(new List<int>(array), 0);
            //foreach(var number in result)
            //{
            //    Console.WriteLine(number);
            //}
            quickSort.arraySort(ref array, 0, array.Length - 1);
            foreach(var number in array)
            {
                Console.Write($"{number},");

            }
            Console.WriteLine("----");
        }
    }

    class QuickSort
    {
        public List<int> Sort(List<int> list, int pivotIndex)
        {
            if(list.Count <= 1)
            {
                return list;
            }
            List<int> result = new List<int>();
            List<int> left = new List<int>();
            List<int> right = new List<int>();

            for (int index = 1; index < list.Count; index++)
            {
                if (list[pivotIndex] < list[index])
                {
                    right.Add(list[index]);
                }
                else
                {
                    left.Add(list[index]);
                }
            }
            result.AddRange(Sort(left, 0));
            result.Add(list[pivotIndex]);
            result.AddRange(Sort(right, 0));
            return result;
        }

        public void arraySort(ref int[] array, int left, int right)
        {
            if(left < right)//left가 0부터 시작, right가 array Length - 1부터 시작하기 때문에 Over 할 일 없다.
            {
                int leftCursor = left;
                int rightCursor = right;
                
                while(leftCursor < rightCursor)// left + 1해서 leftCursor가 rightCursor랑 같아서 걸리는 부분은 여기서 걸러짐
                {
                    while (leftCursor < right)
                    {
                        if (array[leftCursor] < array[left])
                            leftCursor++;
                        else
                            break;
                    }
                    while (leftCursor < rightCursor && rightCursor > left)
                    {
                        if (array[rightCursor] > array[left])
                            rightCursor--;
                        else
                            break;
                    }
                    if(leftCursor < rightCursor)
                        Swap(ref array[leftCursor], ref array[rightCursor]);
                    foreach (var number in array)
                    {
                        Console.Write($"{number},");

                    }
                    Console.WriteLine("----");
                }
                Swap(ref array[leftCursor], ref array[left]);
                foreach (var number in array)
                {
                    Console.Write($"{number},");

                }
                Console.WriteLine("----");
                arraySort(ref array, left, leftCursor - 1);
                arraySort(ref array, rightCursor + 1, right);
            }
        }

        public void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
    }
}
