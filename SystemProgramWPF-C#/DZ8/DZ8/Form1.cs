using DZ8;

namespace DZ8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.SetStartPosition(this); // Передаємо посилання на головну форму
            if (form2.ShowDialog() == DialogResult.OK)
            {
                listBoxProducts.Items.Add(form2.Product.ToString());
            }
        }

        private void buttonEdit_Click(object sender, EventArgs e)
        {
            if (listBoxProducts.SelectedIndex == -1)
            {
                MessageBox.Show("Виберіть продукт для його редагування.");
                return;
            }

            string selectedItem = listBoxProducts.SelectedItem.ToString();
            Product selectedProduct;

            try
            {
                selectedProduct = Product.FromString(selectedItem);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Неможливо редагувати ваш продукт: " + ex.Message);
                return;
            }

            Form2 form2 = new Form2(selectedProduct);
            form2.SetStartPosition(this); // Передаємо посилання на головну форму
            if (form2.ShowDialog() == DialogResult.OK)
            {
                listBoxProducts.Items[listBoxProducts.SelectedIndex] = form2.Product.ToString();
            }
        }

        private void buttonRemove_Click(object sender, EventArgs e)
        {
            if (listBoxProducts.SelectedIndex == -1)
            {
                MessageBox.Show("Виберіть продукт для його видалення.");
                return;
            }

            listBoxProducts.Items.RemoveAt(listBoxProducts.SelectedIndex);
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            listBoxProducts.Items.Clear();
        }
    }
}