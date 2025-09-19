
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
        [Category("Wp�ata")]
        public void Wp�ata_PoprawnaKwota_Wp�ataWykonanaPoprawnie()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            // Act
            var res = rachunek.Wp�a�(100);
            decimal aktualneSaldo = (decimal)saldoRef.GetValue(rachunek);

            // Assert
            Assert.AreEqual(100, aktualneSaldo);
            Assert.IsTrue(res);
        }


        [Test]
        [Category("Wp�ata")]
        public void Wp�ata_NiepoprawnaKwota_B��dPr�baWp�atyZaPomoc�UjemnejKwoty()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            // Act
            var res = rachunek.Wp�a�(-100);
            decimal aktualneSaldo = (decimal)saldoRef.GetValue(rachunek);

            // Assert
            Assert.AreEqual(0, aktualneSaldo);
            Assert.IsFalse(res);
        }

        [Test]
        [Category("Wp�ata")]
        public void Wp�ata_WielokrotnaPoprawnaKwota_Wp�ataWykonanaPoprawnie()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            // Act
            rachunek.Wp�a�(100);
            rachunek.Wp�a�(100);
            rachunek.Wp�a�(100);
            var res = rachunek.Wp�a�(100);
            decimal aktualneSaldo = (decimal)saldoRef.GetValue(rachunek);

            // Assert
            Assert.AreEqual(400, aktualneSaldo);
            Assert.IsTrue(res);
        }

        [Test]
        [Category("Wp�ata")]
        public void Wp�ata_WielokrotnaNiepoprawnaKwota_B��dPr�baWp�atyZaPomoc�UjemnejKwoty()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            // Act
            rachunek.Wp�a�(100);
            rachunek.Wp�a�(-100);
            var res = rachunek.Wp�a�(-100);
            rachunek.Wp�a�(0);
            decimal aktualneSaldo = (decimal)saldoRef.GetValue(rachunek);

            // Assert
            Assert.AreEqual(100, aktualneSaldo);
            Assert.IsFalse(res);
        }
    }
}
