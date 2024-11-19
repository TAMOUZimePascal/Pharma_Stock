-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : sam. 25 mai 2024 à 13:53
-- Version du serveur : 10.4.22-MariaDB
-- Version de PHP : 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `pharmastock`
--

-- --------------------------------------------------------

--
-- Structure de la table `produit`
--

CREATE TABLE `produit` (
  `idPro` int(5) NOT NULL,
  `codePro` varchar(30) NOT NULL,
  `nomPro` varchar(50) NOT NULL,
  `dosage` varchar(50) NOT NULL,
  `caracteristique` varchar(255) NOT NULL,
  `prixUnit` float NOT NULL,
  `qtePro` int(15) NOT NULL,
  `dateExpiration` date DEFAULT NULL,
  `codeType` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `produit`
--

INSERT INTO `produit` (`idPro`, `codePro`, `nomPro`, `dosage`, `caracteristique`, `prixUnit`, `qtePro`, `dateExpiration`, `codeType`) VALUES
(9, 'PAR001', 'paracétamol', '250mg', '5', 4000, 4, '2024-05-30', 'COM001'),
(10, 'PAR0010', 'paracétamol', '250mg', '', 4000, 0, NULL, 'COM0021'),
(11, 'PAR0011', 'paracétamol', '500mg', '2', 4000, 0, '2024-05-22', 'COM0022'),
(12, 'ZIK0012', 'zikkar', '250mg', '5', 4000, 0, '2024-06-24', 'COM0023'),
(13, 'VIT0013', 'VitamineC', '500ml', '8', 10000, 5, '2024-05-29', 'SIR0024');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `produit`
--
ALTER TABLE `produit`
  ADD PRIMARY KEY (`idPro`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `produit`
--
ALTER TABLE `produit`
  MODIFY `idPro` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
