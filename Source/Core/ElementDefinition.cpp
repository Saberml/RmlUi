/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "precompiled.h"
#include "ElementDefinition.h"
#include "StyleSheetNode.h"
#include "../../Include/Rocket/Core/Log.h"

namespace Rocket {
namespace Core {

ElementDefinition::ElementDefinition()
{
}

ElementDefinition::~ElementDefinition()
{
}

// Initialises the element definition from a list of style sheet nodes.
void ElementDefinition::Initialise(const std::vector< const StyleSheetNode* >& style_sheet_nodes)
{
	// Merge the default (non-pseudo-class) properties.
	for (size_t i = 0; i < style_sheet_nodes.size(); ++i)
		properties.Merge(style_sheet_nodes[i]->GetProperties());
}

// Returns a specific property from the element definition's base properties.
const Property* ElementDefinition::GetProperty(PropertyId id) const
{
	return properties.GetProperty(id);
}

// Returns the list of properties this element definition defines for an element with the given set of pseudo-classes.
void ElementDefinition::GetDefinedProperties(PropertyNameList& property_names) const
{
	for (PropertyMap::const_iterator i = properties.GetProperties().begin(); i != properties.GetProperties().end(); ++i)
		property_names.insert((*i).first);
}

// Destroys the definition.
void ElementDefinition::OnReferenceDeactivate()
{
	delete this;
}


}
}
