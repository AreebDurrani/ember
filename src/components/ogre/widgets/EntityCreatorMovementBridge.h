//
// C++ Interface: EntityCreatorMovementBridge
//
// Description: 
//
//
// Author: Erik Hjortsberg <erik.hjortsberg@gmail.com>, (C) 2009
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.//
//
#ifndef EMBEROGRE_GUIENTITYCREATORMOVEMENTBRIDGE_H
#define EMBEROGRE_GUIENTITYCREATORMOVEMENTBRIDGE_H

#include "components/ogre/manipulation/IMovementBridge.h"
#include <wfmath/point.h>

namespace Ogre
{
class SceneNode;
}
namespace EmberOgre {

class DetachedEntity;

namespace Gui {

class EntityCreator;

/**
@brief A movement bridge which knows how to move a DetachedEntity instance, which is a temporary preview entity used by the EntityCreator.
@author Erik Hjortsberg <erik.hjortsberg@gmail.com>
*/
class EntityCreatorMovementBridge : public IMovementBridge
{
public:
    /**
     * @brief Ctor.
     * @param entityCreator The owning entity creator instance.
     * @param entity The entity which should be moved.
     * @param node The node to which the entity belongs.
     */
    EntityCreatorMovementBridge(EntityCreator& creator, DetachedEntity& entity, Ogre::SceneNode* node);

    /**
     * @brief Dtor.
     */
    virtual ~EntityCreatorMovementBridge();
    
	virtual const WFMath::Quaternion& getOrientation() const;
	virtual const WFMath::Point<3>& getPosition() const;
	virtual void setPosition(const WFMath::Point<3>& position);
	virtual void move(const WFMath::Vector<3>& directionVector);
	virtual void setRotation (int axis, WFMath::CoordType angle);
	virtual void setOrientation(const WFMath::Quaternion& rotation);
	virtual void yaw(WFMath::CoordType angle);
	
	virtual void finalizeMovement();
	virtual void cancelMovement();
	
private:

	/**
	 * @brief The entity which should be moved.
	 */
	DetachedEntity& mEntity;
	
	/**
	 * @brief The entity creator which owns the entity.
	 */
	EntityCreator& mCreator;
	
	/**
	 * @brief The node to which the entity is attached.
	 */
	Ogre::SceneNode* mNode;
	
	/**
	 * @brief The current orientation.
	 */
	mutable WFMath::Quaternion mOrientation;
	/**
	 * @brief The current position.
	 */
	mutable WFMath::Point<3> mPosition;
};

}

}

#endif