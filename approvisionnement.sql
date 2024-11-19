-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : sam. 25 mai 2024 à 14:43
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
-- Structure de la table `approvisionnement`
--

CREATE TABLE `approvisionnement` (
  `idAp` int(5) NOT NULL,
  `codeAp` varchar(50) NOT NULL,
  `dateAp` date NOT NULL,
  `codePers` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `approvisionnement`
--

INSERT INTO `approvisionnement` (`idAp`, `codeAp`, `dateAp`, `codePers`) VALUES
(8, 'APP01', '2024-05-15', 'Bjr'),
(9, 'APP09', '2024-05-15', 'Bjr'),
(14, 'APP10', '2024-05-21', 'Bjr'),
(15, 'APP15', '2024-05-22', 'Bjr'),
(16, 'APP16', '2024-05-22', 'Bjr'),
(17, 'APP17', '2024-05-22', 'Bjr'),
(18, 'APP18', '2024-05-22', 'Bjr'),
(19, 'APP19', '2024-05-22', 'Bjr'),
(20, 'APP20', '2024-05-24', 'P002'),
(28, 'APP21', '2024-05-25', 'P002');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `approvisionnement`
--
ALTER TABLE `approvisionnement`
  ADD PRIMARY KEY (`idAp`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `approvisionnement`
--
ALTER TABLE `approvisionnement`
  MODIFY `idAp` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
