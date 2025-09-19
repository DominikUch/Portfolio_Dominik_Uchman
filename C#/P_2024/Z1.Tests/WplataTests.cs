
using NUnit.Framework;
using System.Reflection;
using Z1;
using Z1;

namespace Z1.Tests
{
    [TestFixture]
    class WplataTests
    {
        FieldInfo saldoRef = typeof(RachunekBankowy).GetField("saldo", BindingFlags.NonPublic | BindingFlags.Instance);

        [Test]
        [Category("Wp³ata")]
        public void Wp³ata_PoprawnaKwota_Wp³ataWykonanaPoprawnie()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            // Act
            var res = rachunek.Wp³aæ(100);
            decimal aktualneSaldo = (decimal)saldoRef.GetValue(rachunek);

            // Assert
            Assert.AreEqual(100, aktualneSaldo);
            Assert.IsTrue(res);
        }


        [Test]
        [Category("Wp³ata")]
        public void Wp³ata_NiepoprawnaKwota_B³¹dPróbaWp³atyZaPomoc¹UjemnejKwoty()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            // Act
            var res = rachunek.Wp³aæ(-100);
            decimal aktualneSaldo = (decimal)saldoRef.GetValue(rachunek);

            // Assert
            Assert.AreEqual(0, aktualneSaldo);
            Assert.IsFalse(res);
        }

        [Test]
        [Category("Wp³ata")]
        public void Wp³ata_WielokrotnaPoprawnaKwota_Wp³ataWykonanaPoprawnie()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            // Act
            rachunek.Wp³aæ(100);
            rachunek.Wp³aæ(100);
            rachunek.Wp³aæ(100);
            var res = rachunek.Wp³aæ(100);
            decimal aktualneSaldo = (decimal)saldoRef.GetValue(rachunek);

            // Assert
            Assert.AreEqual(400, aktualneSaldo);
            Assert.IsTrue(res);
        }

        [Test]
        [Category("Wp³ata")]
        public void Wp³ata_WielokrotnaNiepoprawnaKwota_B³¹dPróbaWp³atyZaPomoc¹UjemnejKwoty()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            // Act
            rachunek.Wp³aæ(100);
            rachunek.Wp³aæ(-100);
            var res = rachunek.Wp³aæ(-100);
            rachunek.Wp³aæ(0);
            decimal aktualneSaldo = (decimal)saldoRef.GetValue(rachunek);

            // Assert
            Assert.AreEqual(100, aktualneSaldo);
            Assert.IsFalse(res);
        }
    }
}
