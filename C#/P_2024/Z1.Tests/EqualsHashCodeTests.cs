
using NUnit.Framework;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class EqualsHashCodeTests
    {
        [Test]
        [Category("EqualsHashCode")]
        public void Equals_PorownujeRachunkiBankowe_RetunrnsTrueWhenEqual()
        {
            // Arrange
            RachunekBankowy rachunek1 = new RachunekOsobisty("123456789", "Jan Kowalski");
            RachunekBankowy rachunek2 = new RachunekOsobisty("123456789", "Anna Nowak");

            // Act
            bool result = rachunek1.Equals(rachunek2);

            // Assert
            Assert.IsTrue(result);
        }

        [Test]
        [Category("EqualsHashCode")]
        public void Equals_PorownujeRachunekBankowyZString_RetunrnsTrueWhenEqual()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            string numerRachunku = "123456789";

            // Act
            bool result = rachunek.Equals(numerRachunku);

            // Assert
            Assert.IsTrue(result);
        }

        [Test]
        [Category("EqualsHashCode")]
        public void GetHashCode_ZwracaPrawidlowyHashCode()
        {
            // Arrange
            RachunekBankowy rachunek1 = new RachunekOsobisty("123456789", "Jan Kowalski");
            RachunekBankowy rachunek2 = new RachunekOsobisty("123456789", "Janina Kowalska");

            // Assert
            Assert.AreEqual(rachunek1.GetHashCode(), rachunek2.GetHashCode());
        }
    }
}
