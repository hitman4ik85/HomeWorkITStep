namespace DZ8
{
    partial class Form1
    {
        private ListBox listBoxProducts;
        private Button buttonAdd;
        private Button buttonEdit;
        private Button buttonRemove;
        private Button buttonClear;

        private void InitializeComponent()
        {
            listBoxProducts = new ListBox();
            buttonAdd = new Button();
            buttonEdit = new Button();
            buttonRemove = new Button();
            buttonClear = new Button();

            SuspendLayout();

            // Фон форми
            BackgroundImage = Image.FromFile("магазин-фон.jpeg");
            BackgroundImageLayout = ImageLayout.Stretch;

            // listBoxProducts
            listBoxProducts.FormattingEnabled = true;
            listBoxProducts.Location = new Point(30, 30);
            listBoxProducts.Size = new Size(500, 300);
            listBoxProducts.BackColor = Color.Beige;
            listBoxProducts.ForeColor = Color.DarkSlateGray;

            // buttonAdd
            buttonAdd.Text = "Add Product";
            buttonAdd.Location = new Point(550, 30);
            buttonAdd.Size = new Size(150, 30);
            buttonAdd.BackColor = Color.LightGreen;
            buttonAdd.ForeColor = Color.DarkGreen;
            buttonAdd.Click += buttonAdd_Click;

            // buttonEdit
            buttonEdit.Text = "Edit Product";
            buttonEdit.Location = new Point(550, 70);
            buttonEdit.Size = new Size(150, 30);
            buttonEdit.BackColor = Color.LightBlue;
            buttonEdit.ForeColor = Color.DarkBlue;
            buttonEdit.Click += buttonEdit_Click;

            // buttonRemove
            buttonRemove.Text = "Remove Product";
            buttonRemove.Location = new Point(550, 110);
            buttonRemove.Size = new Size(150, 30);
            buttonRemove.BackColor = Color.LightCoral;
            buttonRemove.ForeColor = Color.DarkRed;
            buttonRemove.Click += buttonRemove_Click;

            // buttonClear
            buttonClear.Text = "Clear List";
            buttonClear.Location = new Point(550, 150);
            buttonClear.Size = new Size(150, 30);
            buttonClear.BackColor = Color.LightGoldenrodYellow;
            buttonClear.ForeColor = Color.DarkOrange;
            buttonClear.Click += buttonClear_Click;

            // Form1
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(750, 400);
            Controls.Add(listBoxProducts);
            Controls.Add(buttonAdd);
            Controls.Add(buttonEdit);
            Controls.Add(buttonRemove);
            Controls.Add(buttonClear);
            Name = "Form1";
            Text = "Product Manager";
            ResumeLayout(false);
        }
    }
}