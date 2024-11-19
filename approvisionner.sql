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
-- Structure de la table `approvisionner`
--

CREATE TABLE `approvisionner` (
  `codeAp` varchar(50) NOT NULL,
  `codePro` varchar(50) NOT NULL,
  `qteApprovisionne` int(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `approvisionner`
--

INSERT INTO `approvisionner` (`codeAp`, `codePro`, `qteApprovisionne`) VALUES
('APP10', 'PAR001', 0),
('APP15', 'PAR0011', 0),
('APP16', 'VIT0013', 0),
('APP17', 'VIT0013', 0),
('APP17', 'PAR001', 0),
('APP18', 'PAR0011', 0),
('APP18', 'VIT0013', 0),
('APP19', 'VIT0013', 0),
('APP19', 'PAR001', 0),
('APP20', 'ZIK0012', 0),
('APP20', 'PAR001', 0),
('APP20', 'VIT0013', 0),
('APP21', 'ZIK0012', 5);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
