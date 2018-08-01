#pragma once
#include "vdvertexattributebase.h"

template <typename T>
class VDVertexAttributeT : public VDVertexAttributeBase {
private:
	CArrayT<T> data;
protected:
	virtual void WriteDataValue(bStream::CFileStream * writer, const T & value) = 0;
public:
	VDVertexAttributeT(AttributeID attribId, uint8_t attribType) {
		attributeType = attribType;
		attributeId = attribId;
		componentCount = 0;
		exponent = 0;
	}

	CArrayT<T>* GetData() {
		return data;
	}

	void AddData(const T* data, int count) {
		for (int i = 0; i < count; i++)
		{
			if (!this->data.contains(data[i]))
				this->data.append(data[i]);
		}
	}

	void WriteData(bStream::CFileStream* writer) {
		for (int i = 0; i < data.size(); i++)
		{
			WriteDataValue(writer, data[i]);
		}
	}
};