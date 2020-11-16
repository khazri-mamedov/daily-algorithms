#pragma once

#include <queue>
#include <memory>

namespace dailyalgorithms
{
    template<typename T>
    class ObjectPool
    {
        public:
        ObjectPool() = default;
        ~ObjectPool() = default;

        // No copy ctor and assignment operator
        ObjectPool(const ObjectPool<T>&) = delete;
        ObjectPool& operator=(const ObjectPool<T>&) = delete;

        std::shared_ptr<T> getObject()
        {
            if (freeObjects.empty())
            {
                freeObjects.emplace(std::make_unique<T>());
            }

            std::unique_ptr<T> freeObject(std::move(freeObjects.front()));
            freeObjects.pop();

            std::shared_ptr<T> returnableObject(freeObject.release(), [this] (T* t) {
                this->freeObjects.emplace(t);
            });

            return returnableObject;
        }

        private:
        std::queue<std::unique_ptr<T>> freeObjects;
    };
}