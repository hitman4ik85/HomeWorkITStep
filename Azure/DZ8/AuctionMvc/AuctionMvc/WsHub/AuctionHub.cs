using Microsoft.AspNetCore.SignalR;

namespace AuctionMvc.WsHub
{
    public class AuctionHub : Hub
    {
        //public override Task OnConnectedAsync()
        //{
        //    Console.WriteLine($"Client connected: {Context.ConnectionId}");
        //    return base.OnConnectedAsync();
        //}

        public async Task MakeBid(string userId, string lot, int price) 
        {
            await Clients.All.SendAsync("NewBid", userId, lot, price);
        }
    }
}
