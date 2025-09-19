
using NUnit.Framework;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class DodajRachunekTests
    {
        [Test]
        [Category("DodajRachunek")]
        public void DodajRachunek_RachunekOsobisty_DodajeDoListyRachunkow()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekOsobisty("123456", "Jan Kowalski");

            // Act
            systemBankowy.DodajRachunek(rachunek);

            // Assert
            Assert.Contains(rachunek, systemBankowy.RachunkiBankowe);
        }

        [Test]
        [Category("DodajRachunek")]
        public void DodajRachunek_RachunekFirmowy_DodajeDoListyRachunkow()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekFirmowy("654321", "Anna Nowak", "Nowak Sp. z o.o.");

            // Act
            systemBankowy.DodajRachunek(rachunek);

            // Assert
            Assert.Contains(rachunek, systemBankowy.RachunkiBankowe);
        }
    }
}
