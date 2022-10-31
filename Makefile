TARGET_EXEC := calc

BUILD_DIR := ./build

$(BUILD_DIR)/$(TARGET_EXEC):
	mkdir -p $(dir $@);
	cd build;
	cmake ..;
	make;

.PHONY: clean test
clean:
	rm -r $(BUILD_DIR)

test:
	./$(BUILD_DIR)/test

-include $(DEPS)
