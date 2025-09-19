
using NUnit.Framework;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class CompareToTests
    {
        [Test]
        [Category("CompareTo")]
        public void CompareTo_RachunekOsobisty_WiekszyWynikGdyWlascicieleJestPozniejWAlfabecie()
        {
            // Arrange
            RachunekBankowy rachunek1 = new RachunekOsobisty("123456789", "Kowalski");
            RachunekBankowy rachunek2 = new RachunekOsobisty("987654321", "Nowak");

            // Act
            int result = rachunek1.CompareTo(rachunek2);

            // Assert
            Assert.Less(result, 0);
        }

        [Test]
        [Category("CompareTo")]
        public void CompareTo_RachunekOsobisty_MniejszyWynikGdyWlascicieleJestWczesniejWAlfabecie()
        {
            // Arrange
            RachunekBankowy rachunek1 = new RachunekOsobisty("123456789", "Nowak");
            RachunekBankowy rachunek2 = new RachunekOsobisty("987654321", "Kowalski");

            // Act
            int result = rachunek1.CompareTo(rachunek2);

            // Assert
            Assert.Greater(result, 0);
        }

        [Test]
        [Category("CompareTo")]
        public void CompareTo_RachunekOsobisty_RownyWynikGdyWlascicieleSaTacySami()
        {
            // Arrange
            RachunekBankowy rachunek1 = new RachunekOsobisty("123456789", "Kowalski");
            RachunekBankowy rachunek2 = new RachunekOsobisty("987654321", "Kowalski");

            // Act
            int result = rachunek1.CompareTo(rachunek2);

            // Assert
            Assert.AreEqual(0, result);
        }
    }
}
