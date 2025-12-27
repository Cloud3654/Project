using System.Diagnostics;
Stopwatch sw = new Stopwatch();
Random rd = new Random();
double best = int.MaxValue;

while (true)
{
    Console.WriteLine("Wait...");
    int t = rd.Next(2000, 5001);
    Thread.Sleep(t);
    Console.Write("Press Enter!");
    sw.Start();
    Console.ReadLine();
    sw.Stop();
    Console.Write($"Record: {sw.ElapsedMilliseconds} ms");
    if (sw.ElapsedMilliseconds < best)
    {
        best = sw.ElapsedMilliseconds;
        Console.WriteLine(" (New Record!)");
    }
    else Console.WriteLine();
    sw.Reset();
}
