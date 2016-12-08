using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestKontrolek
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();          //została dodana zmiana
        }

        private void obrocStrzalki(object sender, EventArgs e)
        {
            switch (blockArrow1.Direction)
            {
                case ArrowDirection.Left:  blockArrow1.Direction = ArrowDirection.Down;  break;
                case ArrowDirection.Down:  blockArrow1.Direction = ArrowDirection.Right; break;
                case ArrowDirection.Right: blockArrow1.Direction = ArrowDirection.Up;    break;
                case ArrowDirection.Up:    blockArrow1.Direction = ArrowDirection.Left;  break;
            }
            switch (blockArrow2.Direction)
            {
                case ArrowDirection.Left: blockArrow2.Direction = ArrowDirection.Down; break;
                case ArrowDirection.Down: blockArrow2.Direction = ArrowDirection.Right; break;
                case ArrowDirection.Right: blockArrow2.Direction = ArrowDirection.Up; break;
                case ArrowDirection.Up: blockArrow2.Direction = ArrowDirection.Left; break;
            }
            switch (blockArrow3.Direction)
            {
                case ArrowDirection.Left: blockArrow3.Direction = ArrowDirection.Down; break;
                case ArrowDirection.Down: blockArrow3.Direction = ArrowDirection.Right; break;
                case ArrowDirection.Right: blockArrow3.Direction = ArrowDirection.Up; break;
                case ArrowDirection.Up: blockArrow3.Direction = ArrowDirection.Left; break;
            }
            switch (blockArrow4.Direction)
            {
                case ArrowDirection.Left: blockArrow4.Direction = ArrowDirection.Down; break;
                case ArrowDirection.Down: blockArrow4.Direction = ArrowDirection.Right; break;
                case ArrowDirection.Right: blockArrow4.Direction = ArrowDirection.Up; break;
                case ArrowDirection.Up: blockArrow4.Direction = ArrowDirection.Left; break;
            }
        }
    }
}
