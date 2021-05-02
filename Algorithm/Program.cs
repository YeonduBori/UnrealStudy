using System;
using System.Collections.Generic;

namespace Algorithm
{
    #region quciksort
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        QuickSort quickSort = new QuickSort();
    //        int[] array = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    //        //List<int> result = quickSort.Sort(new List<int>(array), 0);
    //        //foreach(var number in result)
    //        //{
    //        //    Console.WriteLine(number);
    //        //}
    //        quickSort.arraySort(ref array, 0, array.Length - 1);
    //        foreach (var number in array)
    //        {
    //            Console.Write($"{number},");

    //        }
    //        Console.WriteLine("----");
    //    }
    //}

    //class QuickSort
    //{
    //    public List<int> Sort(List<int> list, int pivotIndex)
    //    {
    //        if (list.Count <= 1)
    //        {
    //            return list;
    //        }
    //        List<int> result = new List<int>();
    //        List<int> left = new List<int>();
    //        List<int> right = new List<int>();

    //        for (int index = 1; index < list.Count; index++)
    //        {
    //            if (list[pivotIndex] < list[index])
    //            {
    //                right.Add(list[index]);
    //            }
    //            else
    //            {
    //                left.Add(list[index]);
    //            }
    //        }
    //        result.AddRange(Sort(left, 0));
    //        result.Add(list[pivotIndex]);
    //        result.AddRange(Sort(right, 0));
    //        return result;
    //    }

    //    public void arraySort(ref int[] array, int left, int right)
    //    {
    //        if (left < right)//left가 0부터 시작, right가 array Length - 1부터 시작하기 때문에 Over 할 일 없다.
    //        {
    //            int leftCursor = left;
    //            int rightCursor = right;

    //            while (leftCursor < rightCursor)// left + 1해서 leftCursor가 rightCursor랑 같아서 걸리는 부분은 여기서 걸러짐
    //            {
    //                while (leftCursor < right)
    //                {
    //                    if (array[leftCursor] < array[left])
    //                        leftCursor++;
    //                    else
    //                        break;
    //                }
    //                while (leftCursor < rightCursor && rightCursor > left)
    //                {
    //                    if (array[rightCursor] > array[left])
    //                        rightCursor--;
    //                    else
    //                        break;
    //                }
    //                if (leftCursor < rightCursor)
    //                    Swap(ref array[leftCursor], ref array[rightCursor]);
    //                foreach (var number in array)
    //                {
    //                    Console.Write($"{number},");

    //                }
    //                Console.WriteLine("----");
    //            }
    //            Swap(ref array[leftCursor], ref array[left]);
    //            foreach (var number in array)
    //            {
    //                Console.Write($"{number},");

    //            }
    //            Console.WriteLine("----");
    //            arraySort(ref array, left, leftCursor - 1);
    //            arraySort(ref array, rightCursor + 1, right);
    //        }
    //    }

    //    public void Swap(ref int a, ref int b)
    //    {
    //        int temp = a;
    //        a = b;
    //        b = temp;
    //    }
    //}
    #endregion

    #region merge sort
    //class Program
    //{
    //    static int[] testArray = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    //    static void Main(string[] args)
    //    {
    //        int[] result = MergeSort(testArray);
    //        foreach (var number in result)
    //        {
    //            Console.WriteLine(number);
    //        }
    //    }

    //    static int[] MergeSort(int[] array)
    //    {
    //        int[] resultArray = Split(array);
    //        return resultArray;
    //    }

    //    static int[] Split(int[] original)
    //    {
    //        if (original.Length <= 1)
    //            return original;

    //        int middleIndex = original.Length / 2;
    //        int[] leftArray = new int[middleIndex];
    //        int[] rightArray = new int[original.Length - middleIndex];

    //        for (int index = 0; index < original.Length; index++)
    //        {
    //            if (index < middleIndex)
    //                leftArray[index] = original[index];
    //            else
    //                rightArray[index - middleIndex] = original[index];
    //        }

    //        return Merge(Split(leftArray), Split(rightArray));
    //    }

    //    static int[] Merge(int[] leftArray, int[] rightArray)
    //    {
    //        int[] mergeResult = new int[leftArray.Length + rightArray.Length];
    //        int leftCursor = 0;
    //        int rightCursor = 0;
    //        int mergeIndex = 0;
    //        while (leftCursor < leftArray.Length && rightCursor < rightArray.Length)
    //        {
    //            if (leftArray[leftCursor] < rightArray[rightCursor])
    //            {
    //                mergeResult[mergeIndex++] = leftArray[leftCursor++];
    //            }
    //            else
    //            {
    //                mergeResult[mergeIndex++] = rightArray[rightCursor++];
    //            }
    //        }

    //        while (leftCursor < leftArray.Length || rightCursor < rightArray.Length)
    //        {
    //            if (leftCursor < leftArray.Length)
    //            {
    //                mergeResult[mergeIndex++] = leftArray[leftCursor++];
    //            }
    //            else if (rightCursor < rightArray.Length)
    //            {
    //                mergeResult[mergeIndex++] = rightArray[rightCursor++];
    //            }
    //        }
    //        return mergeResult;
    //    }
    //}
    #endregion

    #region 프로그래머스 월간 챌린지 4월 괄호 체크
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        string[] testCase = {"[](){}", "}]()[{", "[)(]", "}}}}", "("};
    //        int[] results = {3, 2, 0, 0, 0 };
    //        Solution solution = new Solution();
    //        for(int index = 0; index < results.Length; index++)
    //        {
    //            if (solution.solution(testCase[index]) != results[index])
    //                Console.WriteLine($"틀렸습니다. Case[{index}] : {solution.solution(testCase[index])}");
    //            else
    //                Console.WriteLine($"정답입니다. Case[{index}]");
    //        }

    //    }
    //}

    //public class Solution
    //{
    //    public int solution(string s)
    //    {
    //        int answer = 0;
    //        List<char> sentence = new List<char>(s.ToCharArray());
    //        for(int loop = 0; loop < s.Length; loop++)
    //        {
    //            char end = sentence[sentence.Count - 1];
    //            sentence.Insert(0, end);
    //            sentence.RemoveAt(sentence.Count - 1);
    //            if(checkValidate(sentence))
    //            {
    //                answer++;
    //            }
    //        }
    //        return answer;
    //    }

    //    public bool checkValidate(List<char> validateList)
    //    {
    //        Stack<char> checkStack = new Stack<char>();
    //        for(int index = 0; index < validateList.Count; index++)
    //        {
    //            if (checkClose(validateList[index]))
    //            {
    //                if (checkStack.Count != 0)
    //                {
    //                    switch(checkStack.Peek())
    //                    {
    //                        case '{':
    //                            if (validateList[index] == '}')
    //                                checkStack.Pop();
    //                            else
    //                                return false;
    //                            break;
    //                        case '[':
    //                            if (validateList[index] == ']')
    //                                checkStack.Pop();
    //                            else
    //                                return false;
    //                            break;
    //                        case '(':
    //                            if (validateList[index] == ')')
    //                                checkStack.Pop();
    //                            else
    //                                return false;
    //                            break;
    //                    }
    //                }
    //                else
    //                    return false;
    //            }
    //            else
    //                checkStack.Push(validateList[index]);
    //        }
    //        if (checkStack.Count != 0)
    //            return false;
    //        return true;
    //    }

    //    public bool checkClose(char check)
    //    {
    //        char[] checkChar = { ']', ')', '}' };
    //        foreach(var close in checkChar)
    //        {
    //            if (check == close)
    //                return true;
    //        }
    //        return false;
    //    }
    //}
    #endregion

    #region BFS, DFS
    class Tree
    {
        //Head Always Fist Node
        public Node Head;

        public void BFS()
        {
            Console.WriteLine(Head.data);
            Queue<Node> needVisitNode = new Queue<Node>();
            foreach(var node in Head.leafNodes)
            {
                Console.WriteLine(node.data);
                needVisitNode.Enqueue(node);
            }

            while(needVisitNode.Count != 0)
            {
                Node node = needVisitNode.Dequeue();
                node.BFS();
            }
        }

        public void DFS()
        {
            Head.DFS();
        }
    }

    class Node
    {
        public int data;
        public List<Node> leafNodes;

        public Node(int number)
        {
            data = number;
        }

        public void AddNode(Node node)
        {
            leafNodes = leafNodes ?? new List<Node>();
            leafNodes.Add(node);
        }

        public void BFS()
        {
            if(leafNodes != null)
            {
                Queue<Node> needToVisit = new Queue<Node>();
                foreach (var node in leafNodes)
                {
                    //이미 들렀던 노드라면 Queue에 넣지 않는다. 출력도 X
                    //이 경우엔 Acyclic에 해당
                    Console.WriteLine(node.data);
                    needToVisit.Enqueue(node);
                }

                while (needToVisit.Count != 0)
                {
                    Node node1 = needToVisit.Dequeue();
                    node1.BFS();
                }
            }
        }

        public void DFS()
        {
            Console.WriteLine(data);
            if(leafNodes != null)
            {
                foreach (var node in leafNodes)
                {
                    node.DFS();
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World"); <- for testing

            Tree tree = new Tree();
            tree.Head = new Node(1);
            tree.Head.AddNode(new Node(10));
            tree.Head.AddNode(new Node(7));
            int count = 14;
            foreach(var node in tree.Head.leafNodes)
            {
                node.AddNode(new Node(count++));
                node.AddNode(new Node(count++));
            }

            tree.BFS();

            Console.WriteLine("===================");

            tree.DFS();
        }
    }
    #endregion
}
