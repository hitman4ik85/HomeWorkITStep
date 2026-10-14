using System;
using System.Collections.Generic;
using System.Threading;
using System.Windows.Forms;

namespace DZ3
{
    public partial class Form1 : Form
    {
        private Thread primeThread;
        private bool isRunning;

        public Form1()
        {
            InitializeComponent();
            isRunning = false;
        }

        private bool Chuslo(int num)
        {
            if (num < 2) return false;
            for (int i = 2; i <= Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                    return false;
            }
            return true;
        }

        private void GenChusel(int nuz_mezha, int verh_mezha)
        {
            listBoxPrimes.Invoke((Action)(() => listBoxPrimes.Items.Clear()));
            for (int i = nuz_mezha; i <= verh_mezha && isRunning; i++)
            {
                if (Chuslo(i))
                {
                    listBoxPrimes.Invoke((Action)(() => listBoxPrimes.Items.Add(i)));
                    Thread.Sleep(200);
                }
            }
            isRunning = false;
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            if (isRunning)
            {
                StopGen();
            }
            listBoxPrimes.Items.Clear();

            int nuz_mezha = string.IsNullOrEmpty(textBoxLowerLimit.Text) ? 2 : Convert.ToInt32(textBoxLowerLimit.Text);
            int verh_mezha = string.IsNullOrEmpty(textBoxUpperLimit.Text) ? int.MaxValue : Convert.ToInt32(textBoxUpperLimit.Text);

            primeThread = new Thread(() => GenChusel(nuz_mezha, verh_mezha));
            isRunning = true;
            primeThread.Start();
        }

        private void buttonStop_Click(object sender, EventArgs e)
        {
            StopGen();
        }

        private void StopGen()
        {
            if (isRunning)
            {
                isRunning = false;
                primeThread.Join();
            }
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            listBoxPrimes.Items.Clear();
        }
    }
}
