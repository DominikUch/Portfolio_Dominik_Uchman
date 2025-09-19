
using NUnit.Framework;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class RejestrTransakcjiTests
    {
        [Test]
        [Category("RejestrTransakcji")]
        public void DodajRachunek_OperacjaNaRachunku_RejestrujeOperacjeWHistorii()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekOsobisty("123456", "Jan Kowalski");
            systemBankowy.DodajRachunek(rachunek);

            // Act
            rachunek.Wp³aæ(200m);

            // Assert
            Assert.IsTrue(systemBankowy.HistoriaTranskacji.Count > 0);
            var operacja = systemBankowy.HistoriaTranskacji[0];
            Assert.AreEqual(200m, operacja.Kwota);
            Assert.AreEqual("Wp³ata œrodków", operacja.Opis);
        }

        [Test]
        [Category("RejestrTransakcji")]
        public void DodajRachunek_BrakOperacji_NieRejestrujeOperacjiWHistorii()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekOsobisty("123456", "Jan Kowalski");

            // Act
            systemBankowy.DodajRachunek(rachunek);

            // Assert
            Assert.IsEmpty(systemBankowy.HistoriaTranskacji);
        }

        [Test]
        [Category("RejestrTransakcji")]
        public void DodajRachunek_WieleOperacji_RejestrujeWszystkieOperacjeWHistorii()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekOsobisty("123456", "Jan Kowalski");
            systemBankowy.DodajRachunek(rachunek);

            // Act
            rachunek.Wp³aæ(300m);
            rachunek.Wyp³aæ(150m);

            // Assert
            Assert.AreEqual(2, systemBankowy.HistoriaTranskacji.Count);

            var operacja1 = systemBankowy.HistoriaTranskacji[0];
            Assert.AreEqual(300m, operacja1.Kwota);
            Assert.AreEqual("Wp³ata œrodków", operacja1.Opis);

            var operacja2 = systemBankowy.HistoriaTranskacji[1];
            Assert.AreEqual(150m, operacja2.Kwota);
            Assert.AreEqual("Wyp³ata œrodków", operacja2.Opis);
        }

        [Test]
        [Category("RejestrTransakcji")]
        public void DodajRachunek_WieleRachunkow_RejestrujeOperacjeDlaKazdego()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunekOsobisty = new RachunekOsobisty("123456", "Jan Kowalski");
            var rachunekFirmowy = new RachunekFirmowy("654321", "Anna Nowak", "Nowak Sp. z o.o.");
            systemBankowy.DodajRachunek(rachunekOsobisty);
            systemBankowy.DodajRachunek(rachunekFirmowy);

            // Act
            rachunekOsobisty.Wp³aæ(100m);
            rachunekFirmowy.Wp³aæ(200m);
            rachunekFirmowy.Wyp³aæ(50m);

            // Assert
            Assert.AreEqual(3, systemBankowy.HistoriaTranskacji.Count);

            var operacja1 = systemBankowy.HistoriaTranskacji[0];
            Assert.AreEqual(100m, operacja1.Kwota);
            Assert.AreEqual("Wp³ata œrodków", operacja1.Opis);

            var operacja2 = systemBankowy.HistoriaTranskacji[1];
            Assert.AreEqual(200m, operacja2.Kwota);
            Assert.AreEqual("Wp³ata œrodków", operacja2.Opis);

            var operacja3 = systemBankowy.HistoriaTranskacji[2];
            Assert.AreEqual(50m, operacja3.Kwota);
            Assert.AreEqual("Wyp³ata œrodków", operacja3.Opis);
        }

        [Test]
        [Category("RejestrTransakcji")]
        public void DodajRachunek_NieDodanoRachunku_BrakOperacjiWHistorii()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekOsobisty("123456", "Jan Kowalski");

            // Act
            // Nie dodajemy rachunku do systemu, wiêc historia powinna pozostaæ pusta.

            // Assert
            Assert.IsEmpty(systemBankowy.HistoriaTranskacji);
        }

        [Test]
        [Category("RejestrTransakcji")]
        public void DodajRachunek_DodajRachunekRejestrujeKazdaOperacje()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekOsobisty("123456", "Jan Kowalski");
            systemBankowy.DodajRachunek(rachunek);

            // Act
            rachunek.Wp³aæ(100m);
            rachunek.Wp³aæ(200m);
            rachunek.Wyp³aæ(50m);

            // Assert
            Assert.AreEqual(3, systemBankowy.HistoriaTranskacji.Count);

            var operacja1 = systemBankowy.HistoriaTranskacji[0];
            Assert.AreEqual(100m, operacja1.Kwota);
            Assert.AreEqual("Wp³ata œrodków", operacja1.Opis);

            var operacja2 = systemBankowy.HistoriaTranskacji[1];
            Assert.AreEqual(200m, operacja2.Kwota);
            Assert.AreEqual("Wp³ata œrodków", operacja2.Opis);

            var operacja3 = systemBankowy.HistoriaTranskacji[2];
            Assert.AreEqual(50m, operacja3.Kwota);
            Assert.AreEqual("Wyp³ata œrodków", operacja3.Opis);
        }
    }
}
