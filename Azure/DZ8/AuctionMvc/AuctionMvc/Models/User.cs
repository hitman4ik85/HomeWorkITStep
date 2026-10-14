using Azure;
using Azure.Data.Tables;

namespace AuctionMvc.Models
{
    public class User : ITableEntity
    {
        public string Email { get; set; }
        public string Password { get; set; }
        public string AvatarUrl { get; set; }
        public int Balance { get; set; }
        public DateTime CreatedAt { get; set; }

        public string PartitionKey { get; set; }
        public string RowKey { get; set; }
        public DateTimeOffset? Timestamp { get; set; }
        public ETag ETag { get; set; }

        public User(string email, string password, string avatarUrl)
        {
            Email = email;
            Password = password;
            AvatarUrl = avatarUrl;

            Balance = 0;
            CreatedAt = DateTime.UtcNow;

            PartitionKey = "User";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTime.UtcNow;
            ETag = new ETag();

        }

        public User()
        {
            Email = "";
            Password = "";
            AvatarUrl = "";

            Balance = 0;
            CreatedAt = DateTime.UtcNow;

            PartitionKey = "User";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTime.UtcNow;
            ETag = new ETag();

        }
    }
}
