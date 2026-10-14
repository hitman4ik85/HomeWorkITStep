namespace DZ8
{
    partial class Form2
    {
        private TextBox textBoxName;
        private TextBox textBoxCountry;
        private TextBox textBoxPrice;
        private Button buttonOk;
        private Button buttonCancel;

        private void InitializeComponent()
        {
            textBoxName = new TextBox();
            textBoxCountry = new TextBox();
            textBoxPrice = new TextBox();
            buttonOk = new Button();
            buttonCancel = new Button();

            SuspendLayout();

            // Фон форми
            BackgroundImage = Image.FromFile("додавання у список продуктів та зміна списку.jpeg");
            BackgroundImageLayout = ImageLayout.Stretch;

            // textBoxName
            textBoxName.PlaceholderText = "Product Name";
            textBoxName.Location = new Point(30, 30);
            textBoxName.Size = new Size(300, 30);
            textBoxName.BackColor = Color.WhiteSmoke;
            textBoxName.ForeColor = Color.DarkSlateGray;

            // textBoxCountry
            textBoxCountry.PlaceholderText = "Product Country";
            textBoxCountry.Location = new Point(30, 70);
            textBoxCountry.Size = new Size(300, 30);
            textBoxCountry.BackColor = Color.WhiteSmoke;
            textBoxCountry.ForeColor = Color.DarkSlateGray;

            // textBoxPrice
            textBoxPrice.PlaceholderText = "Product Price";
            textBoxPrice.Location = new Point(30, 110);
            textBoxPrice.Size = new Size(300, 30);
            textBoxPrice.BackColor = Color.WhiteSmoke;
            textBoxPrice.ForeColor = Color.DarkSlateGray;

            // buttonOk
            buttonOk.Text = "Ok";
            buttonOk.Location = new Point(30, 160);
            buttonOk.Size = new Size(100, 30);
            buttonOk.BackColor = Color.LightGreen;
            buttonOk.ForeColor = Color.DarkGreen;
            buttonOk.Click += buttonOk_Click;

            // buttonCancel
            buttonCancel.Text = "Cancel";
            buttonCancel.Location = new Point(140, 160);
            buttonCancel.Size = new Size(100, 30);
            buttonCancel.BackColor = Color.LightCoral;
            buttonCancel.ForeColor = Color.DarkRed;
            buttonCancel.Click += buttonCancel_Click;

            // Form2
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(400, 250);
            Controls.Add(textBoxName);
            Controls.Add(textBoxCountry);
            Controls.Add(textBoxPrice);
            Controls.Add(buttonOk);
            Controls.Add(buttonCancel);
            Name = "Form2";
            Text = "Product Details";
            ResumeLayout(false);
        }
    }
}