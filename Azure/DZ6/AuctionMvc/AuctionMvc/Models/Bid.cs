namespace AuctionMvc.Models
{
    public class Bid
    {
        public string UserRowKey { get; set; }
        public string LotRowKey { get; set; }
        public int Value { get; set; }
        public DateTime CreatedAt { get; set; }
        public int MaxPrice { get; set; }
    }
}
