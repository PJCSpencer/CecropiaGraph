//
//  sdmPainterPathUtility.h
//  CecropiaGraph
//
//  Created by Peter JC Spencer on 31/03/2016.
//
//

#ifndef sdmPainterPathUtility_h
#define sdmPainterPathUtility_h

/// \file sdmPainterPathUtility.h
///
/// \brief Contains the definition of the PainterPathUtility class.
///

#include <QObject>
#include <QPainterPath>


namespace spencers
{
    ///
    /// \brief PainterPathUtility class.
    ///
    class PainterPathUtility : public QObject
    {
    public: // Static members.
        
        ///
        /// \brief Creates a rounded rect path.
        ///
        /// \param [in] size            The QSize for path.
        /// \param [in] cornerRadius    The corner radius for path.
        ///
        /// \return                     A new QPainterPath object.
        ///
        static auto createRoundedRectPath(const QSize size,
                                          const qreal cornerRadius) -> QPainterPath;
        
        ///
        /// \brief Creates a rounded triangle path.
        ///
        /// \param [in] size            The QSize for path.
        /// \param [in] cornerRadius    The corner radius for path.
        ///
        /// \return                     A new QPainterPath object.
        ///
        static auto createTrianglePath(const int numPoints,
                                       const qreal rotation,
                                       const QSize size,
                                       const qreal cornerRadius) -> QPainterPath;
        
        ///
        /// \brief Creates a torpedo path.
        ///
        /// \param [in] size            The QSize for path.
        /// \param [in] cornerRadius    The end point radius for path.
        ///
        /// \return                     A new QPainterPath object.
        ///
        static auto createTorpedoPath(const QSize size,
                                      const qreal cornerRadius) -> QPainterPath;
    };
}

#endif


