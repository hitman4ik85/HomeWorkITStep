using AuctionMvc.Models;
using Azure.Data.Tables;
using Microsoft.AspNetCore.SignalR;

namespace AuctionMvc.WsHub
{
    public interface IAuctionHub
    {
        Task NewBid(string userId, string lot, int price);
        Task BidRejected(string lot, string reason); // ✅ додано метод для повідомлення
    }

    public class AuctionHub : Hub<IAuctionHub>
    {
        private readonly TableClient tableClient;

        public AuctionHub(TableClient tableClient)
        {
            this.tableClient = tableClient;
        }

        public async Task MakeBid(string userId, string lot, int price)
        {
            // Отримати лот (тепер будь-хто може робити ставку)
            Lot? lotItem = tableClient.Query<Lot>(x => x.Name == lot).FirstOrDefault(); //прибрав UserRowKey == userId

            if (lotItem == null)
            {
                await Clients.Caller.BidRejected(lot, "Lot not found.");
                return;
            }

            // 🔒 Перевірка ставки: ціна не менше поточної і не більше максимальної
            if (price <= lotItem.Price)
            {
                await Clients.Caller.BidRejected(lot, "Your bid is too low.");
                return;
            }

            if (price > lotItem.MaxPrice)
            {
                await Clients.Caller.BidRejected(lot, "Your bid exceeds the maximum price.");
                return;
            }

            // ✅ Якщо все добре — оновити ставку
            lotItem.Price = price;
            await tableClient.UpdateEntityAsync<Lot>(lotItem, lotItem.ETag, TableUpdateMode.Replace);
            await Clients.All.NewBid(userId, lot, price);
        }
    }
}