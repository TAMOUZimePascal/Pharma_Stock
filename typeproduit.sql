-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : sam. 25 mai 2024 à 16:51
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
-- Structure de la table `typeproduit`
--

CREATE TABLE `typeproduit` (
  `idType` int(5) NOT NULL,
  `codeType` varchar(15) NOT NULL,
  `typePro` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `typeproduit`
--

INSERT INTO `typeproduit` (`idType`, `codeType`, `typePro`) VALUES
(20, 'COM001', 'Comprimé'),
(21, 'COM0021', 'Comprimé'),
(22, 'COM0022', 'Comprimé'),
(23, 'COM0023', 'Comprimé'),
(24, 'SIR0024', 'Siro');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `typeproduit`
--
ALTER TABLE `typeproduit`
  ADD PRIMARY KEY (`idType`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `typeproduit`
--
ALTER TABLE `typeproduit`
  MODIFY `idType` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
