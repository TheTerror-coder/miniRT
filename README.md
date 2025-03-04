# Project "RAYTRACING ENGINE miniLibX"

Description : Développement d’un moteur de RayTracing en C pour la génération d’images 3D à partir de scènes définies par des objets géométriques simples (sphères, plans, cylindres). Le projet inclut la gestion de la lumière (éclairage ambiant, diffuse, etc.), ainsi que des transformations sur les objets (translation, rotation). Il utilise la bibliothèque miniLibX pour l'affichage et la gestion de la fenêtre graphique.
Compétences et technologies utilisées :

    Langage : C
    Graphisme : RayTracing, miniLibX pour l'affichage, gestion des fenêtres et images
    Mathématiques : Formules géométriques pour les intersections de rayons, calculs de lumière et transformations d'objets
    Gestion de la mémoire : Allocation dynamique et gestion des fuites mémoire
    Gestion des erreurs : Validation des fichiers de scène, gestion des erreurs de configuration

Responsabilités et Réalisations :

    Développement du moteur de RayTracing :
        Création d'un moteur de RayTracing simple capable de générer des images 3D à partir de scènes définies par des objets géométriques de base (sphères, plans, cylindres).
        Implémentation de l'algorithme de RayTracing pour effectuer les intersections de rayons avec les objets et calculer la couleur des pixels à afficher.
        Gestion de la lumière ambiante, diffuse et spot, pour offrir un éclairage réaliste dans la scène.

    Gestion des objets et transformations :
        Implémentation des objets géométriques de base (plan, sphère, cylindre), avec leurs propriétés définies dans un fichier de scène .rt.
        Ajout des transformations pour déplacer (translation) et orienter (rotation) les objets dans l’espace 3D, ainsi que le contrôle de leur taille.
        Prise en charge des éclairages et de l’orientation des caméras pour donner la perspective correcte.

    Utilisation de miniLibX pour l’affichage :
        Intégration de miniLibX pour gérer la fenêtre graphique et l'affichage de l'image générée par RayTracing.
        Mise en place de l'interface utilisateur avec gestion des événements (fermeture de fenêtre, appui sur la touche ESC) pour quitter proprement le programme.

    Gestion de la scène à partir de fichiers .rt :
        Lecture de fichiers .rt pour décrire la scène avec des éléments comme la lumière, la caméra, et les objets 3D (en respectant une syntaxe rigoureuse pour chaque type d’élément).
        Validation des fichiers de scène pour garantir la configuration correcte des objets et éviter les erreurs de syntaxe (affichage de messages d’erreur explicites en cas de problème).

    Optimisation des performances :
        Amélioration de l'algorithme de RayTracing pour générer des images de manière efficace tout en conservant un rendu visuellement correct.
        Optimisation de la gestion de la mémoire et des ressources pour éviter les fuites et garantir la stabilité du programme.

    Tests et validation :
        Création de plusieurs scènes de test avec des configurations variées pour valider le rendu des objets, la gestion de la lumière, et l’application correcte des transformations.
        Débogage pour garantir l’absence de fuites mémoire et assurer un comportement sans erreur même en cas de mauvaise configuration du fichier de scène.

    Bonus (optionnels) :
        Mise en place de fonctionnalités supplémentaires comme le rendu de textures (ex. : bump-mapping sur une sphère), l’implémentation d’effets de réflexion ou de transparence, et la gestion des ombres douces.
        Amélioration du moteur pour rendre des scènes plus complexes, en mettant l’accent sur la gestion des erreurs et la performance.

Résultats :

    Génération d’images 3D : Création d'un moteur fonctionnel capable de rendre des scènes réalistes à partir d'une description simple dans un fichier .rt.
    Interface utilisateur fluide : Affichage d’images via miniLibX, avec gestion correcte des événements utilisateur pour quitter ou interagir avec la fenêtre.
    Validations robustes des entrées : Validation stricte des fichiers .rt et gestion des erreurs pour garantir une expérience sans bugs.
    Performances optimisées : Le RayTracing est calculé de manière efficace, avec une gestion optimale de la mémoire et des ressources.
