﻿#pragma once

/*!
* \class ISynchronized
* \brief Interface pour élément synchronisé
*
* Cette interface vise à homogénéiser la notion de temps (timer) pour les classes qui en dépendent.
*/

/*! \todo Enventuellement factory de modules ? */

class ISynchronized
{
public:
    /*!
     * \fn virtual ~ISynchornized()
     * \brief Destructeur
     */
    virtual ~ISynchronized(){};
    
    /*!
     * \fn virtual void clock(int time)
     * \brief Methode appellé à chaque tick d'horloge liée
     */
    virtual void clock(int time) = 0;
};