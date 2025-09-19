
using NUnit.Framework;
using Z1;
using static Z1.RachunekBankowy;
namespace Z1.Tests
{
    [TestFixture]
    class ComparerTests
    {
        [Test]
        [Category("Comparer")]
        public void Compare_RachunekOsobisty_SaldoXWiekszeNizSaldoY_WynikMniejszyOdZera()
        {
            // Arrange
            RachunekBankowy rachunekX = new RachunekOsobisty("123456789", "Jan Kowalski");
            rachunekX.Wp³aæ(1000); // Saldo = 1000
            RachunekBankowy rachunekY = new RachunekOsobisty("987654321", "Anna Nowak");
            rachunekY.Wp³aæ(500); // Saldo = 500
            var comparer = new SortowanieSaldaComparer();

            // Act
            int result = comparer.Compare(rachunekX, rachunekY);

            // Assert
            Assert.Less(result, 0);
        }

        [Test]
        [Category("Comparer")]
        public void Compare_RachunekOsobisty_SaldoXMniejszeNizSaldoY_WynikWiekszyOdZera()
        {
            // Arrange
            RachunekBankowy rachunekX = new RachunekOsobisty("123456789", "Jan Kowalski");
            rachunekX.Wp³aæ(500); // Saldo = 500
            RachunekBankowy rachunekY = new RachunekOsobisty("987654321", "Anna Nowak");
            rachunekY.Wp³aæ(1000); // Saldo = 1000
            var comparer = new SortowanieSaldaComparer();

            // Act
            int result = comparer.Compare(rachunekX, rachunekY);

            // Assert
            Assert.Greater(result, 0);
        }

        [Test]
        [Category("Comparer")]
        public void Compare_RachunekOsobisty_SaldoXRowneSaldoY_WynikRownyZero()
        {
            // Arrange
            RachunekBankowy rachunekX = new RachunekOsobisty("123456789", "Jan Kowalski");
            rachunekX.Wp³aæ(1000); // Saldo = 1000
            RachunekBankowy rachunekY = new RachunekOsobisty("987654321", "Anna Nowak");
            rachunekY.Wp³aæ(1000); // Saldo = 1000
            var comparer = new SortowanieSaldaComparer();

            // Act
            int result = comparer.Compare(rachunekX, rachunekY);

            // Assert
            Assert.AreEqual(0, result);
        }
    }
}
